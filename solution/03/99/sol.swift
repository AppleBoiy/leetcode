class Solution {
    func calcEquation(_ equations: [[String]], _ values: [Double], _ queries: [[String]]) -> [Double] {
        var graph = [String: [String: Double]]()

        for (i, equation) in equations.enumerated() {
            let u = equation[0]
            let v = equation[1]
            let value = values[i]

            graph[u, default: [:]][v] = value
            graph[v, default: [:]][u] = 1.0 / value
        }

        func bfs(_ start: String, _ end: String) -> Double {
            if graph[start] == nil || graph[end] == nil {
                return -1.0
            }
            if start == end {
                return 1.0
            }

            var queue: [(String, Double)] = [(start, 1.0)]
            var visited = Set<String>()
            visited.insert(start)

            while !queue.isEmpty {
                let (node, value) = queue.removeFirst()

                if let neighbors = graph[node] {
                    for (neighbor, weight) in neighbors {
                        if neighbor == end {
                            return value * weight
                        }
                        if !visited.contains(neighbor) {
                            visited.insert(neighbor)
                            queue.append((neighbor, value * weight))
                        }
                    }
                }
            }

            return -1.0
        }

        var results = [Double]()
        for query in queries {
            let u = query[0]
            let v = query[1]
            results.append(bfs(u, v))
        }

        return results
    }
}