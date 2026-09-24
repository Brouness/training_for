import collections

def insert(q, d):
    q.append(d)

def delete(q):
    try:
        m = 0
        for i in range(len(q)):
            if q[i] > q[m]:
                m = i
        item = q[m]
        del q[m]
        return item
    except IndexError:
        print("Queue empty.")
        exit()

def is_empty(q):
    return len(q) == 0
def dijkstra(mapp, start, target):
    distances = {start: 0}
    came_from = {}
    priority_queue = [(0, start)]
    visited = set()
    while (priority_queue):
        cost, current = priority_queue.pop()
        if current == target:
            path = [current]
            while current != start:
                current = came_from[current]
                path.append(current)
            return path.reverse()
        for neighbor in mapp[current]:
            edge_cost = neighbor[0]
            new_cost = cost + edge_cost
            if neighbor not in distances or new_cost < distances[neighbor]:
                distances[neighbor] = new_cost
                came_from[neighbor] = current
                insert(priority_queue)
                
