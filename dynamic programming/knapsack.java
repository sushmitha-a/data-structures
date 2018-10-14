package pack;

import java.util.Scanner;

public class knapsack {

	
		
	public static int doKnap(Integer[] wt,Integer[] val,int lim) {
		int[][] kn = new int[wt.length+1][lim+1];
		for(int i=0;i<wt.length+1;i++)
		{
			for(int j=0;j<lim+1;j++)
			{
				if(i==0||j==0)
				{
					kn[i][j]=0;
				}
				else if(wt[i-1]<=j){
					kn[i][j]= Math.max(val[i-1]+kn[i-1][j-wt[i-1]],kn[i-1][j]);
					
				}
				else {
					kn[i][j]=kn[i-1][j];
				}
			}
			
		}
		
		
		
		return kn[wt.length][lim];
		
	}

	
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println("enter the no of items");
        int i;
        
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Integer[] wt = new Integer[n];
		Integer[] val = new Integer[n];
		System.out.println("enter the items");
		for(i=0;i<n;i++)
		{
			wt[i]=sc.nextInt();
		}
		System.out.println("enter the vals");
		for(i=0;i<n;i++)
		{
			val[i]=sc.nextInt();
		}
		int lim;
		System.out.println("enter the required weight");
		lim = sc.nextInt();
		System.out.println("the max value that can be obtained is "+doKnap(wt,val,lim));
		
	}

}
