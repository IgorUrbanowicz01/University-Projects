param companies_count, integer, > 0;
param airports_count,  integer, > 0;

set companies := 1..companies_count;
set airports  := 1..airports_count;

param max_gallons_from_companies    {company in companies},                      integer, >= 0;
param min_gallons_for_airports      {airport in airports},                       integer, >= 0;
param cost_from_company_to_airport  {company in companies, airport in airports}, integer, >= 0;

var gallons_from_company_to_airport {company in companies, airport in airports}, integer, >= 0;
var gallons_for_airports            {airport in airports},                       integer, >= 0;
var gallons_from_companies          {company in companies},                      integer,import Pkg;
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

  @variable(model, route_picked[1:cities_count, 1:cities_count], Bin)
  # @variable(model, route_picked[1:cities_count, 1:cities_count] >= 0) # doesn't change anything
  @constraint(model, [from = 1:cities_count, to = 1:cities_count; costs[from, to] == 0], route_picked[from, to] == 0)
  @constraint(model, [city = 1:cities_count], sum(route_picked[city, :]) - sum(route_picked[:, city]) == produce[city])
  @constraint(model, sum(durations .* route_picked) <= duration_upper_bound)

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
 >= 0;

airports_gallons  {airport in airports}:  (sum{company in companies} gallons_from_company_to_airport[company, airport]) =
                                          gallons_for_airports[airport];

companies_gallons {company in companies}: (sum{airport in airports} gallons_from_company_to_airport[company, airport]) =
                                          gallons_from_companies[company];

s.t. airports_gallons_in_bounds {airport in airports}:  gallons_for_airports[airport] >= min_gallons_for_airports[airport];
s.t. companies_gallons_in_bounds{company in companies}: gallons_from_companies[company] <= max_gallons_from_companies[company];

minimize cost: sum{company in companies, airport in airports} (gallons_from_company_to_airport[company, airport] *
                                                               cost_from_company_to_airport[company, airport]);

solve;

printf "Minimal cost of all deliveries: %d\n", cost;

printf "All companies deliver fuel: %s\n",
       (if card({company in companies: gallons_from_companies[company] == 0}) == 0 then "true" else "false");
printf "All companies delivered all fuel: %s\n",
       (if card({company in companies: (gallons_from_companies[company] > 0 && gallons_from_companies[company] == max_gallons_from_companies[company])}) == card({company in companies: gallons_from_companies[company] > 0}) then "true" else "false");

data;

param companies_count := 3;
param airports_count  := 4;

param max_gallons_from_companies :=
1 275000
2 550000
3 660000
;

param min_gallons_for_airports :=
1 110000
2 220000
3 330000
4 440000
;

param cost_from_company_to_airport: 1 2 3 4 :=
1 10 10 9 11
2 7 11 12 13
3 8 14 4 9
;

end;
