require 'sinatra'
require 'json'

post '/' do
  body = "#{JSON.parse(request.body.string).values.first.gsub(/\]\]/,"").gsub(/\[\[/,"").split("],[").inject([]) {|new_a, i| new_a << i.split(",").map {|j| j.to_i }}.inject(0) {|sum, i| sum += i.min}}"
end


