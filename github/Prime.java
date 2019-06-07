import java.util.*;
import java.math.*;
import java.io.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=Integer.parseInt(sc.nextLine());
		//System.out.println("Number of cases "+t);
		int i=0;
		 String s=sc.nextLine();
		do
		{   
		    if(i>0) s=sc.nextLine();
		    //System.out.println(s);
		    
		    
		    BigInteger b=new BigInteger(s);
		   // System.out.println(b);
		    Boolean ans=b.isProbablePrime(1);
		    if(ans==true)System.out.println("Prime");
		    else System.out.println("Not Prime");
		    i=i+1;
		    
		}while(i<t);
	}
}
