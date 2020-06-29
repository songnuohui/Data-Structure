package test1;

public class KMP {
    public static void main(String[] args) {
        int index=kmp("abcabaabaabcacb", "abaabcac");
        System.out.print("字符串第一次出现的位置从第"+index+"个位置开始");
    }
    /**
     * 创建next数组
     * */
    public static int[] get_next(char[] ch){
        int [] next=new int[ch.length];//创建一个长度为ch.length的数组
        next[0]=-1;
        next[1]=0;
        int k;
        for (int j=2;j<ch.length;j++){
            k=next[j-1];
            while(k!=-1){
                if(ch[j-1]==ch[k]){
                    next[j]=k+1;
                    break;
                }
                else {
                    k=next[k];
                }
                next[j]=0;
            }
        }
        return next;
    }
    /**
     * 对主串s和模式串t进行KMP模式匹配
     * @param s 主串
     * @param t 模式串
     * @return 若匹配成功，返回t在s中的位置（第一个相同字符对应的位置），若匹配失败，返回-1
     */
    public static int kmp(String s ,String t){
        char[] chars = s.toCharArray();
        char[] chars1 = t.toCharArray();
        int next[]=get_next(chars1);//模式串的next数组
        int i=0,j=0;
        while(i<chars.length&&j<chars1.length){
            if(j==-1||chars[i]==chars1[j]){
                i++;
                j++;
            }
            else {
                j=next[j];
            }
        }
        if(j==chars1.length)
            return i-j+1;
        else
            return -1;
    }
}
