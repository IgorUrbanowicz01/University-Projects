import Pkg;
Pkg.activate(".")
Pkg.add("JuMP")
Pkg.add("GLPK")

using JuMP, GLPK

function solve(costs::Matrix{Int},
	             durations::Matrix{Int},
	             duration_upper_bound::Int,
	             start_city::Int,
       	       end_city::Int)
  cities_count = size(costs, 1)
  produce = zeros(cities_count)
  produce[start_city] = 1
  produce[end_city] = -1

  @assert end_city <= cities_count
  @assert start_city <= cities_count

  model = Model(GLPK.Optimizer)

  @variable(model, route_picked[1:cities_count, 1:cities_count] >= 0)
  # @variable(model, route_picked[1:cities_count, 1:cities_count] >= 0) # doesn't change anything
  @constraint(model, [from = 1:cities_count, to = 1:cities_count; costs[from, to] == 0], route_picked[from, to] == 0)
  @constraint(model, [city = 1:cities_count], sum(route_picked[city, :]) - sum(route_picked[:, city]) == produce[city])
  # @constraint(model, sum(durations .* route_picked) <= duration_upper_bound)

  @objective(model, Min, sum(costs .* route_picked))

  optimize!(model)

  println(termination_status(model))
  println(value.(route_picked))
  println(objective_value(model))
end

costs = [
 0 0 0 0 5 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 4 9 0 0 0 8 0 0 0 0
 0 0 5 0 0 0 9 0 0 0
 0 0 0 0 0 6 0 0 0 0
 0 0 0 8 0 0 7 1 0 0
 0 0 0 0 0 0 0 0 8 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
]

durations = [
 0 0 0 0 6 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 5 2 0 0 0 3 0 0 0 0
 0 0 4 0 0 0 4 0 0 0
 0 0 0 0 0 7 0 0 0 0
 0 0 0 2 0 0 8 1 0 0
 0 0 0 0 0 0 0 0 9 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0
]

duration_upper_bound = 28
start_city = 1
end_city = 9

solve(costs, durations, duration_upper_bound, start_city, end_city)
