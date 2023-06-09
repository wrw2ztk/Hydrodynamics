using QuadGK
using SpecialFunctions
using Plots
# gamma=1, a=1
function n_timeev(r::Float64, t::Float64)
    inte,err = quadgk(q -> q*besselj0(r*q)*exp(-q^2)*cos(t*sqrt(q)), 0, Inf)
    return inte
end
timeplot = plot(t -> n_timeev(0.0, t) , 0, 40)
xlabel!(timeplot, "time,  sqrt(gamma/a)*t")
ylabel!(timeplot, "overdensity")
title!(timeplot, "r=0")
savefig(timeplot, "timeplot.pdf")
@gif for t in LinRange(0.0, 40.0, 324)
    plt = plot( xlim = (0, 20), ylim = (-0.6, 0.6) )
    xlabel!(plt, "radial distance,  r/a")
    ylabel!(plt, "overdensity")
    plot!(plt, r -> n_timeev(r, t) , 0, 20)
end every 1