def mirror_matrix(matrix: list[list[int]]) -> list[list[int]]:
    my_list = []
    for lst in matrix:
        my_list.append(lst[::-1])
    return my_list

print(mirror_matrix([[1,2,3],[4,5,6]]))
print(mirror_matrix([[1,2],[3,4],[5,6]]))
print(mirror_matrix([[7]]))
print(mirror_matrix([[1,2,3,4]]))
print(mirror_matrix([[-1,-2],[-3,-4]]))