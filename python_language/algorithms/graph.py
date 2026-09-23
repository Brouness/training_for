def display_matrix(mat: list[list]) -> None:
    for row in mat:
        print("".join(map(str, row)))

def add_edge(mat, i , j):
    mat[i][j] = 

if __name__ == "__main__":
    vertices: int = 4
    mat: list[list[int]] = [[0] * vertices for _ in range(vertices)]
    mat = [
        [0,1,1,0],
        [1,0,1,0],
        [1,1,0,1],
        [0,0,1,0]
    ]
    print("Adjacency Matrix:")
    display_matrix(mat)
