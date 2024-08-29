use std::collections::{HashMap, VecDeque};

impl Solution {
    pub fn calc_equation(
        equations: Vec<Vec<String>>,
        values: Vec<f64>,
        queries: Vec<Vec<String>>,
    ) -> Vec<f64> {
        let mut graph: HashMap<String, HashMap<String, f64>> = HashMap::new();

        for (i, equation) in equations.iter().enumerate() {
            let u = &equation[0];
            let v = &equation[1];
            let value = values[i];

            graph.entry(u.clone()).or_insert(HashMap::new()).insert(v.clone(), value);
            graph.entry(v.clone()).or_insert(HashMap::new()).insert(u.clone(), 1.0 / value);
        }

        fn bfs(
            graph: &HashMap<String, HashMap<String, f64>>,
            start: &String,
            end: &String,
        ) -> f64 {
            if !graph.contains_key(start) || !graph.contains_key(end) {
                return -1.0;
            }
            if start == end {
                return 1.0;
            }

            let mut queue = VecDeque::new();
            let mut visited = HashMap::new();
            queue.push_back((start.clone(), 1.0));
            visited.insert(start.clone(), true);

            while let Some((node, value)) = queue.pop_front() {
                if let Some(neighbors) = graph.get(&node) {
                    for (neighbor, weight) in neighbors {
                        if neighbor == end {
                            return value * weight;
                        }
                        if !visited.contains_key(neighbor) {
                            visited.insert(neighbor.clone(), true);
                            queue.push_back((neighbor.clone(), value * weight));
                        }
                    }
                }
            }

            -1.0
        }

        let mut results = Vec::new();
        for query in queries {
            let u = &query[0];
            let v = &query[1];
            results.push(bfs(&graph, u, v));
        }

        results
    }
}