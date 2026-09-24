import collections

def bfs(graph, start, target):
    queue = collections.deque([start])
    visited = {start}
    came_from = {}  # maps: node -> the node that discovered it

    while queue:
        current = queue.popleft()
        if current == target:
            # reconstruct path by walking backward
            path = [current]
            while current != start:
                current = came_from[current]
                path.append(current)
            path.reverse()
            return path

        for neighbor in graph[current]:
            if neighbor not in visited:
                visited.add(neighbor)
                came_from[neighbor] = current
                queue.append(neighbor)

    return None
if __name__ == "__main__":
    graph = {
        "start": ["A", "C"],
        "A": ["start", "B"],
        "B": ["end", "A"],
        "C": ["start", "end"],
        "end": ["C", "B"]
    }
    x = bfs(graph, "start", "end")
    print(x)
