

f = open("lineAlongPlane_FullEvolution.txt")

line_count = 0

for lines in readlines(f)

    global line_count += 1
    println(lines)

end

close(f)