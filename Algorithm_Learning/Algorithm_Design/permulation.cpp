 void Perm(string list,  int k, int m )
    { //产生[list[k:m]的所有排列
        if(k==m)
         {  //只剩下一个元素
             for (int i=0;i<=m;i++) 
             {
                 str+=list[i];
             }
            s.insert(str);
            str="";
            
        }
        else  //还有多个元素待排列，递归产生排列
           for (int i=k; i<=m; i++)
            {
               swap(list[k],list[i]);
               Perm(list,k+1,m);   
               swap(list[k],list[i]);         
             }
    }
