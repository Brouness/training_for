"""this is bfs implimentation"""

def add_ege(mat: list[list[int]], i: int, j: int) -> None:
    mat[i][j] = 1
    mat[j][i] = 1

def graph_maker(verteces: int) -> list[list[int]]:
    graph: list[list] = [[0] * verteces for _ in range(verteces)]
    return graph

if __name__ == "__main__":
    grid: list[list[int]] = graph_maker(4)
    print("this is the empty graph")
    for row in grid:
        print("".join(map(str, row)))
    add_ege(grid, 0, 1)
    add_ege(grid, 0, 2)
    add_ege(grid, 2, 3)
    add_ege(grid, 3, 1)
    add_ege(grid, 1, 0)
    print("This is the grid after the graph set")
    for row in grid:
        print("".join(map(str, row)))
    