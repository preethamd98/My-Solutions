class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer> m = new HashMap<>();
        for(int i:nums){m.put(i,m.getOrDefault(i,0) + 1);}
        Queue<Map.Entry<Integer,Integer>> pq = new PriorityQueue(new Comparator<Map.Entry<Integer,Integer>>() {
            @Override
            public int compare(Map.Entry<Integer,Integer> o1, Map.Entry<Integer,Integer> o2) {
                return o1.getValue() - o2.getValue();
            }
        });
        for(Map.Entry<Integer,Integer> i:m.entrySet()){
            if(pq.size()<k){pq.add(i);}
            else if(pq.peek().getValue() < i.getValue()){
                pq.poll();
                pq.add(i);
            }
        }
        int[] ans = new int[k];
        int i = 0;
        while(pq.size()>0){
            ans[i] = pq.peek().getKey();
            pq.poll();
            i++;
        }
        return ans;
    }
}