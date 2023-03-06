include("/home/igor/Desktop/University-Projects/Języki_formalne_techniki_translacji/Lista_1/Zadanie_1(FAM).jl")
include("/home/igor/Desktop/University-Projects/Języki_formalne_techniki_translacji/Lista_1/Zadanie_1(KMP).jl")


base_file = read(open(ARGS[3], "r"),String)
character_list = getUniqeCharacters(base_file)

if  ARGS[1] == "FA"
    qFuncion,m = computerTransitionFuncion(ARGS[2],character_list)
    finiteAtomatonMatcher(base_file,qFuncion,m)
elseif ARGS[1] == "KMP"
    kmpMatcher(base_file, ARGS[2])
else
    println("Zle danne!!")
end
println()

