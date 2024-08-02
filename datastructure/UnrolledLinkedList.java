package com.htdong.leetcode.algorithm;

/**
 * 
 * @author htdong
 * @date 2023-03-02 20:16:52
 */
public class UnrolledLinkedList {

    private int sqrtn;
    private ListNode head;
    public int total;

    public UnrolledLinkedList(int maxSize) {
        sqrtn = Math.max(1, (int)Math.sqrt(maxSize));
        head = new ListNode(sqrtn);
        total = 0;
    }

    public void init(int[] s, int n) {
        ListNode next = head;
        total = n;
        for (int i = 0; i < n; ++i) {
            if (next.size > sqrtn) {
                next.next = new ListNode(sqrtn);
                next.next.pre = next;
                next = next.next;
            }
            next.add(s[i], false);
        }
    }

    public int remove(int i) {
        ListNode next = head;
        while (next != null && i >= next.size) {
            i -= next.size;
            next = next.next;
        }
        if (next != null) {
            --total;
            return next.remove(i);
        }
        return 0;
    }

    public void add(int i, int v) {
        ListNode next = head;
        while (next != null && i > next.size) {
            i -= next.size;
            next = next.next;
        }
        if (next != null) {
            next.add(i, v);
            ++total;
        }
    }

    public int count(int l, int r, int k) {
        ListNode next = head;
        while (next != null && next.size <= l) {
            l -= next.size;
            r -= next.size;
            next = next.next;
        }
        if (next == null) {
            return 0;
        }
        int cnt = 0;
        for (int i = l; i <= Math.min(r, next.size - 1); ++i) {
            if (k == next.list[i]) {
                ++cnt;
            }
        }
        r -= next.size;
        next = next.next;
        while (next != null && r >= next.size) {
            r -= next.size;
            next = next.next;
        }
        for (int i = 0; i <= r; ++i) {
            if (k == next.list[i]) {
                ++cnt;
            }
        }
        return cnt;
    }

    private static class ListNode {
        private ListNode pre, next;
        private int[] list;
        private int sqrtn;
        private int size;

        public ListNode(int sqrtn) {
            this.sqrtn = sqrtn;
            this.list = new int[sqrtn * 2 + 10];
        }

        public int get(int i) {
            return list[i];
        }

        public int remove(int i) {
            int v = get(i);
            for (; i + 1 < size; ++i) {
                list[i] = list[i + 1];
            }
            --size;
            merge();
            return v;
        }

        public void add(int idx, Integer ch) {
            add(idx, ch, true);
        }

        private void add(Integer ch, boolean checksplit) {
            add(size, ch, checksplit);
        }

        private void add(int idx, Integer ch, boolean checksplit) {
            for (int i = size; i > idx; --i) {
                list[i] = list[i - 1];
            }
            list[idx] = ch;
            ++size;
            if (checksplit) {
                split();
            }
        }

        private void merge() {
            if (next != null && size + next.size <= sqrtn) {
                ListNode nn = next;
                for (int i = 0; i < nn.size; ++i) {
                    add(nn.get(i), false);
                }
                next = nn.next;
                if (next != null) {
                    next.pre = this;
                }
            } else if (pre != null && size + pre.size <= sqrtn) {
                pre.merge();
            }
        }

        private void split() {
            if (size > 2 * sqrtn) {
                ListNode nn = new ListNode(sqrtn);
                nn.pre = this;
                nn.next = this.next;
                this.next.pre = nn;
                this.next = nn;
                for (int i = sqrtn + 1; i < size; ++i) {
                    nn.add(list[i], false);
                }
                size -= nn.size;
            }
        }
    }
}