import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static StringTokenizer st;
    private static int n;
    private static int reps = 50000;
    private static double learning_rate = 1;
    private static double _dist = 1;
    private static List<Point> pointList = new ArrayList<>();

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());
            pointList.add(new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken())));

        }
        _dist = go();
        bw.write(String.format("%.2f", _dist) + "\n");
        bw.flush();
        br.close();
        bw.close();
    }

    private static double go() {
        Point curr = getAveragePoint();
        for (int i = 0; i < reps; i++) {
            Point farPoint = getFarPoint(curr);
            curr.x += (farPoint.x - curr.x) * learning_rate;
            curr.y += (farPoint.y - curr.y) * learning_rate;
            curr.z += (farPoint.z - curr.z) * learning_rate;
            learning_rate *= 0.999;
        }
        Point farPoint = getFarPoint(curr);
        return dist(curr, farPoint);
    }

    public static Point getFarPoint(Point curr) {
        Point farPoint = curr;
        for (Point pt : pointList) {
            if (dist(curr, pt) > dist(curr, farPoint))
                farPoint = pt;
        }
        return farPoint;
    }

    public static Point getAveragePoint() {
        Point pt = new Point(0, 0, 0);
        for (Point it : pointList) {
            pt.x += it.x;
            pt.y += it.y;
            pt.z += it.z;
        }
        pt.x /= n;
        pt.y /= n;
        pt.z /= n;
        return pt;
    }

    private static double dist(Point a, Point b) {
        return Math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
    }

    private static class Point {
        double x;
        double y;
        double z;

        public Point(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }
}
