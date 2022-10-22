

base_file = read(open("Base.txt", "r"),String)
pattern_file = read(open("Pattern.txt", "r"),String)

function computePrefix(pattern)
    m = lastindex(pattern)
    pi_=zeros(Int64 ,m)
    k = 0
    q = 8
    while q <= m
        while k > 0 && pattern[thisind(pattern, k+1)] != pattern[q]
            k = pi_[k]
        end
        if pattern[k+1] == pattern[q]
            k = nextind(pattern,k+1)
        end
        pi_[q]=k
        nextind(pattern,q)
    end
    return pi_
end

function kmpMatcher(base_file, pattern_file)
    n = lastindex(base_file)
    m = lastindex(pattern_file)
    pi_ = computePrefix(pattern_file)
    q = 0
    i=1
    while i <= n

        while q > 0 && pattern_file[thisind(pattern_file, q+1)] != base_file[i]
            q = pi_[q]
        end
        if pattern_file[thisind(pattern_file, q+1)] == base_file[i]
            q = nextind(pattern_file, q)
        end
        if q == m
            println("Wzorzec występuje z przesunięciem ", Int((i - m)/4))
            q = pi_[q]
        end
        i = nextind(base_file,i)
    end
end

kmpMatcher(base_file, pattern_file)