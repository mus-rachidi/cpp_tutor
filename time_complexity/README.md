# time complexity


is this algorithm good ????????????????????
1) correct 

2) efficient
    - time complexity
        -> 1 method : run the algorithm on a real machine.
            the running time of an algoritem depends on 

        -> 2 method : freuency count method by time function. 
            | example f(n): 6n^2 + 100n + 300
            | according asymptotic analysis to the most important part is 6n^2
            | throught input
            |   - time taken, in term of input size
            |   - Rate of Growth
            | + big O notation (Worst case)  
            |   f(n) = O(g(n)), there exist constants c, n0 such that f(n) =< c.g(n) for all n > n0
            |   
            |   -> 2n^2 + 150n + 300 ~= O(n^2)
            |   -> 2n^3 + 150n + 300 ~= O(n^3)
            |   -> 4log2(n) + 40 ~= O(log2(n))
            |  + Big Omega (best case)
            |  + Big Theta (average case)
            | used to measure the performance of any algorithm.
            | by providing the order of growth of the function.
            | it gives the upper bound on a function (worst case).
    - space complexity
3) easy to implement

