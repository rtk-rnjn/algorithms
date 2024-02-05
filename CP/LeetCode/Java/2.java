// 2. Add Two Numbers

import java.util.ArrayList;
import java.util.List;

class Solution {
    static class ListNode {
        //CSOFF: VisibilityModifier
        int val;
        ListNode next;
        //CSON: VisibilityModifier

        ListNode(final int newVal) {
            this.val = newVal;
        }
    }

    public ListNode addTwoNumbers(final ListNode l1, final ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode p = l1;
        ListNode q = l2;
        ListNode current = dummy;

        int carry = 0;
        while (p != null || q != null) {
            int x = (p != null) ? p.val : 0;
            int y = (q != null) ? q.val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            current.next = new ListNode(sum % 10);
            current = current.next;
            if (p != null) {
                p = p.next;
            }
            if (q != null) {
                q = q.next;
            }
        }
        if (carry > 0) {
            current.next = new ListNode(carry);
        }
        return dummy.next;
    }

    public static void main(final String[] args) {
        final Solution solution = new Solution();

        final ListNode l1 = new ListNode(2);
        l1.next = new ListNode(4);
        l1.next.next = new ListNode(3);

        final ListNode l2 = new ListNode(5);
        l2.next = new ListNode(6);
        l2.next.next = new ListNode(4);

        ListNode result = solution.addTwoNumbers(l1, l2);
        List<Integer> list = new ArrayList<>();
        while (result != null) {
            list.add(result.val);
            result = result.next;
        }
        System.out.println(list);
    }
}
