import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static StringTokenizer st;
    private static int v, e, start;
    private static Map<Integer, ArrayList<pair>> graph = new HashMap<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        v = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());
        start = Integer.parseInt(br.readLine());
        while (e-- > 0) {
            st = new StringTokenizer(br.readLine());
            int from, to, weight;
            from = Integer.parseInt(st.nextToken());
            to = Integer.parseInt(st.nextToken());
            weight = Integer.parseInt(st.nextToken());
            graph.get(from).add(new pair(to, weight));
        }
    }

    private static class pair {
        public int to;
        public int weight;

        public pair(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }
}
