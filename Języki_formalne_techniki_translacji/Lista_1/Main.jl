include("/home/igor/Desktop/University-Projects/Języki_formalne_techniki_translacji/Lista_1/Zadanie_1(FAM).jl")
include("/home/igor/Desktop/University-Projects/Języki_formalne_techniki_translacji/Lista_1/Zadanie_1(KMP).jl")


temp = readline()
user_input = split(temp, " ")

println(user_input)
base_file = read(open("Base.txt", "r"),String)
character_list = getUniqeCharacters(base_file)

if user_input[1] == "FA"
    qFuncion,m = computerTransitionFuncion(user_input[2],character_list)
    finiteAtomatonMatcher(base_file,qFuncion,m)
elseif user_input[1] == "KMP"
    kmpMatcher(base_file, user_input[2])
else
    println("Zle danne!!")
end

