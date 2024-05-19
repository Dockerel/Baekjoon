import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    public static int n;
    public static int sum;
    public static long ret;
    public static List<Integer> list = new ArrayList<>();
    public static List<Integer> c_list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            list.add(Integer.parseInt(st.nextToken()));
        }

        c_list.add(0);
        for (int i = 0; i < n * 2; i++) {
            c_list.add(c_list.get(i) + list.get(i % n));
        }
        sum = c_list.get(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < i + n; j++) {
                double temp = c_list.get(j) - c_list.get(i);
                if (temp < 0) {
                    ret += Math.ceil(Math.abs(temp) / sum);
                }
            }
        }

        System.out.println(ret);
        br.close();
    }
}