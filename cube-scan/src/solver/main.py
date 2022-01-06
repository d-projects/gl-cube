from rubik.cube import Cube
from rubik.solve import Solver
from rubik.optimize import optimize_moves


cube = Cube("OOOOOOOOOWWWGGGBBBYYYYYYWWWGGGBBBYYYWWWGGGBBBRRRRRRRRR")
solver = Solver(cube)
solver.solve()
print(optimize_moves(solver.moves))


