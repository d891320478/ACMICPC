public class Trie {
    public boolean end;
    public Trie[] next;
    public int len;

    public Trie(boolean end, int len) {
        this.end = end;
        this.next = new Trie[len];
        this.len = len;
    }

    public static void insert(Trie node, String a) {
        for (int i = 0; i < a.length(); ++i) {
            int v = a.charAt(i) - 'a';
            if(node.next[v] == null) {
                node.next[v] = new Trie(false, node.len);
            }
            node = node.next[v];
        }
        node.end = true;
    }
}
