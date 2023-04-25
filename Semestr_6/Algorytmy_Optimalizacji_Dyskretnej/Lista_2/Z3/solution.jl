import Pkg;
Pkg.activate(".")
Pkg.add("JuMP")
Pkg.add("GLPK")

using JuMP, GLPK

function solve(costs::Matrix{Int},
	       min::Matrix{Int},
	       max::Matrix{Int})
  node_count = size(costs, 1)

  model = Model(GLPK.Optimizer)

  @variable(model, flow[1:node_count, 1:node_count] >= 0, Int)

  @constraint(model, [from = 1:node_count, to = 1:node_count; costs[from, to] == 2], flow[from, to] == 0)
  @constraint(model, [from = 1:node_count, to = 1:node_count], flow[from, to] >= min[from, to])
  @constraint(model, [from = 1:node_count, to = 1:node_count; max[from, to] > 0], flow[from, to] <= max[from, to])
  @constraint(model, [node = 1:node_count], sum(flow[node, :]) - sum(flow[:, node]) == 0)

  @objective(model, Min, sum(costs .* flow))

  optimize!(model)

  println(termination_status(model))
  println(value.(flow))
  println(sum(costs .* value.(flow)))
end

costs = [
 2 0 0 0 2 2 2 2
 2 2 2 2 0 0 0 2
 2 2 2 2 0 0 0 2
 2 2 2 2 0 0 0 2
 2 2 2 2 2 2 2 0
 2 2 2 2 2 2 2 0
 2 2 2 2 2 2 2 0
 1 2 2 2 2 2 2 2
]

min = [
 0 10 14 13 0 0 0 0
 0 0  0  0  2 4 3 0
 0 0  0  0  3 6 5 0
 0 0  0  0  5 7 6 0
 0 0  0  0  0 0 0 10
 0 0  0  0  0 0 0 20
 0 0  0  0  0 0 0 18
 0 0  0  0  0 0 0 0
]

max = [
 0 0 0 0 0 0  0  0
 0 0 0 0 3 7  5  0
 0 0 0 0 5 7  10 0
 0 0 0 0 8 12 10 0
 0 0 0 0 0 0  0  0
 0 0 0 0 0 0  0  0
 0 0 0 0 0 0  0  0
 0 0 0 0 0 0  0  0
]

solve(costs, min, max)
