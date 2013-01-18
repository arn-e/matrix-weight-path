import static spark.Spark.*;
import spark.*;
import java.io.*;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class ShortWeight{

  native static int matrixWeight(int[] matrix_values, int rows, int columns);
  static {
    System.loadLibrary("matrix_weight");
  }

  public static void main(String[] args) {
        setPort(9000);

        get(new Route("/") {
            @Override
            public Object handle(Request request, Response response){
                response.type("text/html");
                return "Hello!";
            }
        });

        post(new Route("/"){
            @Override
            public Object handle(Request request, Response response){
                String body = request.body();
                String[] matrixBody = body.split(":");
                String matrixString = matrixBody[1].replaceAll("\\[\\[","\\[").replaceAll("\\]\\]","\\]").replaceAll("\\{","").replaceAll("\\}","").replaceAll("\"",""); 
                
                int rows = matrixRows(matrixString);
                int columns = matrixColumns(matrixString, rows);

                int[] matrixValues = parsedMatrix(matrixString);
                int minimumWeightPath = calculateShortestPath(matrixValues, rows, columns);
                System.out.println("Shortest Path " + minimumWeightPath);              
                return minimumWeightPath;
            }
        });
    }

    private static int calculateShortestPath(int[] matrixValues, int rows, int columns){
        System.out.println(rows);
        System.out.println(columns);
        int lowestWeight = matrixWeight(matrixValues, rows, columns);
        return lowestWeight;
    }

    private static int[] parsedMatrix(String matrixString){
        String[] matrixItems = matrixString.replaceAll("\\[","").replaceAll("\\]","").split(",");
        int[] matrixValues = new int[matrixItems.length];

        for (int i = 0; i < matrixItems.length; i ++){
            try {
                matrixValues[i] = Integer.parseInt(matrixItems[i].replaceAll(" ",""));
            } catch(NumberFormatException nfe) { nfe.printStackTrace(); }
        }
        return matrixValues;
    }
    
    private static int matrixRows(String matrixString){
        int count = 0;

        for (int i = 0; i < matrixString.length(); i ++){
            if (matrixString.charAt(i) == '['){
                count ++;
            }
        }
        return count;
    }
    private static int matrixColumns(String matrixString, int rows){
        int count = 0;

        for (int i = 0; i < matrixString.length(); i ++){
            if (matrixString.charAt(i) == ','){
                count ++;
            }
        }
        count ++;
        return ( count / rows ) ;
    }
}