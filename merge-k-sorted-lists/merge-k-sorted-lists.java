// *
//  * Definition for singly-linked list.
//  * public class ListNode {
//  *     int val;
//  *     ListNode next;
//  *     ListNode() {}
//  *     ListNode(int val) { this.val = val; }
//  *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
//  * }

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        Queue<ListNode> pq = new PriorityQueue<>(new Comparator<ListNode>(){
            public int compare(ListNode o1,ListNode o2){
                return o1.val - o2.val;
            }
        });
        for(ListNode i:lists){if(i!=null){pq.add(i);}}
        ListNode ans = new ListNode(1);
        ListNode sol = ans;
        while(pq.size()>0){
            ListNode top = pq.poll();
            ans.next = new ListNode(top.val);
            ans = ans.next;
            top = top.next;
            if(top != null){pq.add(top);}
        }
        return sol.next;
    }
}