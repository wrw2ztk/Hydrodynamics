using Plots

f_x = open("lineAlongPlane_FullEvolution_x.txt")
f_y = open("lineAlongPlane_FullEvolution_y.txt")

maxEnd = 100.0
distSteps = 1000
maxT = 100.0
timeSteps = 4000


@gif for t in LinRange(0.0, maxT, timeSteps)
    plt = plot(xlim = (-100, 100), ylim = (-1.5, 1.5))
    xlabel!(plt, "x")
    ylabel!(plt,"overdensity")
    printing_t = round(t; sigdigits=4, base=10)
    title!(plt, "t = $printing_t")
    x_array = Array{Float64}(undef,distSteps)
    y_array = Array{Float64}(undef,distSteps)

    for i in 1:(distSteps)
        s_x = readline(f_x)
        s_y = readline(f_y)
        x_array[i] = parse(Float64, s_x)
        y_array[i] = parse(Float64, s_y)
    end
    plot!(plt, x_array, y_array)
        
end every 2    

close(f_x)
close(f_y)