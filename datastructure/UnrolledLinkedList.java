import java.util.HashMap;
import java.util.Map;

/**
 * 
 * @author htdong
 * @date 2023-03-02 20:16:52
 */
public class UnrolledLinkedList {

    private int sqrtn;
    private ListNode head;
    private int total;

    public UnrolledLinkedList(int maxSize) {
        sqrtn = Math.max(1, (int)Math.sqrt(maxSize));
        head = new ListNode(sqrtn);
        total = 0;
    }

    public int size() {
        return total;
    }

    public void init(int[] s, int n) {
        head = new ListNode(sqrtn);
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

    // 返回被删除的值，下标越界时返回 -1
    public int remove(int i) {
        if (i < 0 || i >= total) {
            return -1;
        }
        ListNode next = head;
        while (i >= next.size) {
            i -= next.size;
            next = next.next;
        }
        --total;
        return next.remove(i);
    }

    // 成功时返回 0，下标越界时返回 -1
    public int add(int i, int v) {
        if (i < 0 || i > total) {
            return -1;
        }
        ListNode next = head;
        while (i > next.size) {
            i -= next.size;
            next = next.next;
        }
        next.add(i, v);
        ++total;
        return 0;
    }

    // 返回闭区间 [l, r] 内 k 的个数，下标越界时返回 -1，l > r 时返回 0
    public int count(int l, int r, int k) {
        if (l < 0 || r < 0 || l >= total || r >= total) {
            return -1;
        }
        ListNode next = head;
        while (next.size <= l) {
            l -= next.size;
            r -= next.size;
            next = next.next;
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
            cnt += next.count(k);
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
        private Map<Integer, Integer> freq = new HashMap<>();

        public ListNode(int sqrtn) {
            this.sqrtn = sqrtn;
            this.list = new int[sqrtn * 2 + 10];
        }

        public int get(int i) {
            return list[i];
        }

        public int count(int v) {
            return freq.getOrDefault(v, 0);
        }

        // 计数减到 0 时移除对应的 key
        private void decreaseFreq(int v) {
            freq.merge(v, -1, (a, b) -> a + b == 0 ? null : a + b);
        }

        public int remove(int i) {
            int v = get(i);
            for (; i + 1 < size; ++i) {
                list[i] = list[i + 1];
            }
            --size;
            decreaseFreq(v);
            merge();
            return v;
        }

        public void add(int idx, int ch) {
            add(idx, ch, true);
        }

        private void add(int ch, boolean checksplit) {
            add(size, ch, checksplit);
        }

        private void add(int idx, int ch, boolean checksplit) {
            for (int i = size; i > idx; --i) {
                list[i] = list[i - 1];
            }
            list[idx] = ch;
            ++size;
            freq.merge(ch, 1, Integer::sum);
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
                if (this.next != null) {
                    this.next.pre = nn;
                }
                this.next = nn;
                for (int i = sqrtn + 1; i < size; ++i) {
                    nn.add(list[i], false);
                    decreaseFreq(list[i]);
                }
                size -= nn.size;
            }
        }
    }
}
