// Tests compile, issue in java.library.path them from running
// java -cp "../bin:../lib/*:../src:../bin/libmatrix_weight.dylib:." -Djava.library.path=../bin/libmatrix_weight.dylib ShortWeightTest

import org.junit.Test;
import org.testng.Assert;

public class ShortWeightTest {

	@Test
	public static void testCalculateShortestPath() throws Exception {
		int rows = 3; int columns = 3;
		int[] matrixValues = { 6, 2, 4, 3, 5, 11, 9, 6, 5 };
		int expectedResult = 10;

		int result = ShortWeight.calculateShortestPath(matrixValues, rows, columns);
		Assert.assertEquals(result, expectedResult);
	}

	public static void main(String[] args) {
		try {
			testCalculateShortestPath();
		} catch (Exception e) { e.printStackTrace(); }
	}
}