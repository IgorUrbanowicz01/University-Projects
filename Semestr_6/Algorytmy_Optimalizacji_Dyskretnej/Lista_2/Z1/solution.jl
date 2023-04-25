import Pkg;
Pkg.activate(".env")
Pkg.add("JuMP")
Pkg.add("GLPK")

using JuMP, GLPK;

function solve(max_gallons_from_companies::Vector{Int},
               min_gallons_for_airports::Vector{Int},
               cost_from_company_to_airport::Matrix{Int})
  companies_count = length(max_gallons_from_companies)
  airports_count = length(min_gallons_for_airports)

  @assert size(cost_from_company_to_airport, 1) == companies_count
  @assert size(cost_from_company_to_airport, 2) == airports_count

  model = Model(GLPK.Optimizer)

  @variable(model, gallons_from_company_to_airport[1:companies_count, 1:airports_count] >= 0, Int)
  @variable(model, gallons_for_airports[1:airports_count] >= 0, Int)
  @variable(model, gallons_from_companies[1:companies_count] >= 0, Int)

  for airport in 1:airports_count
    @constraint(model, sum(gallons_from_company_to_airport[company, airport] for company in 1:companies_count) == gallons_for_airports[airport])
  end

  for company in 1:companies_count
    @constraint(model, sum(gallons_from_company_to_airport[company, airport] for airport in 1:airports_count) == gallons_from_companies[company])
  end

  @constraint(model, airports_gallons_in_bounds, gallons_for_airports .>= min_gallons_for_airports)
  @constraint(model, companies_gallons_in_bounds, gallons_from_companies .<= max_gallons_from_companies)

  @objective(model, Min, sum([sum(gallons_from_company_to_airport[company, airport] *
				  cost_from_company_to_airport[company, airport]
				  for airport in 1:airports_count)
			      for company in 1:companies_count]))

  optimize!(model)
  
  gallons_from_companies = value.(gallons_from_companies)

  print(value.(gallons_from_company_to_airport))
  print("Minimum cost of delivering fuel: ", objective_value(model), "\n")
  print("All companies deliver fuel: ", length([1 for gallons in gallons_from_companies if gallons == 0]) == 0, "\n")
  print("All companies deliver all of fuel: ", length([1 for company in 1:companies_count
						         if gallons_from_companies[company] > 0 &&
						            gallons_from_companies[company] < max_gallons_from_companies[company]]) == 0,
	"\n")
end

max_gallons_from_companies = [275000, 550000, 660000]
min_gallons_for_airports = [110000, 220000, 330000, 440000]
cost_from_company_to_airport = [10 10 9 11; 7 11 12 13; 8 14 4 9;]

solve(max_gallons_from_companies, min_gallons_for_airports, cost_from_company_to_airport)
