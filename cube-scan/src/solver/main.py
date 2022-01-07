from rubik.cube import Cube
from rubik.solve import Solver
from rubik.optimize import optimize_moves
from fastapi import FastAPI

app = FastAPI()

@app.get("/valid/{face_colors}")
def valid(face_colors: str):
    try:
        cube = Cube(face_colors)
        return {"valid": True}
    except AssertionError:
        return {"valid": False} 

@app.get("/solve/{face_colors}")
def solve(face_colors: str):
    if valid(face_colors)["valid"] == False:
        return {"error": ["Cube is invalid"]}

    cube = Cube(face_colors)
    solver = Solver(cube)
    solver.solve()
    if not cube.is_solved():
        return {"error": ["The cube could not be solved"]}
    else:
        return {"moves": solver.moves}    



