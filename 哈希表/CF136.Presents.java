//典型的哈希表问题，建立key-value映射
import java.io.InputStreamReader;
import java.util.*;

public class Test {
    public static void main(String[] args) {
        Scanner in = new Scanner(new InputStreamReader(System.in));
        Map<Integer,Integer>map=new HashMap<>();
        int n=in.nextInt();
        for(int i=0;i<n;++i){
            int key=in.nextInt();
            map.put(key,i+1);
        }
        for(int i=0;i<n;++i){
            System.out.printf("%d ",map.get(i+1));
        }
    }
}
