class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < prerequisites.length; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj.get(v).add(u);
        }

        int[] indegree = new int[numCourses];
        for (int i = 0; i < numCourses; i++) {
            for (int j = 0; j < adj.get(i).size(); j++) {
                indegree[adj.get(i).get(j)]++;
            }
        }

        List<Integer> ans = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.add(i);
        }

        while (!q.isEmpty()) {
            int temp = q.poll();
            ans.add(temp);
            for (int i = 0; i < adj.get(temp).size(); i++) {
                int n = adj.get(temp).get(i);
                indegree[n]--;
                if (indegree[n] == 0)
                    q.add(n);
            }
        }

        if (ans.size() == numCourses) {
            int[] result = new int[numCourses];
            for (int i = 0; i < numCourses; i++)
                result[i] = ans.get(i);
            return result;
        }

        return new int[0];
    }
}