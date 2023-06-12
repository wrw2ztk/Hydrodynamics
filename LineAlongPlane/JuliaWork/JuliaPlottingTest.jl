using QuadGK
using Plots
# gamma=1, a=1

f = open("lineAlongPlane_FullEvolution.txt")

for lines in readlines(f)

    println(lines)

end

close(f)

@gif for t in LinRange(0.0, 50.0, 100)
    plt = plot( xlim = (-50, 50), ylim = (-2.0, 2.0) )
    xlabel!(plt, "x")
    ylabel!(plt, "overdensity")

    

    plot!(plt, x_array, y_array)
end every 1