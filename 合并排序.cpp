
void Mergesort(int arr[], int p, int r)
{
    /*
    1. p: 数组的首指针
    2. r: 尾指针
    3. 一个合并排序就是需要先把一个数组分成左右两个部分，
    4. 然后在把左右两个部分归并
    */
    if(p<r){
        int mid = ((r+p)/2);
        Mergesort(arr[], p, mid);//拆分左半部分
        Mergesort(arr[], mid+1, r); // 拆分右半部分
        Merge(arr[], p, mid, r);
    }
}



void Merge(int arr[], int p, int mid, int r)
{
    int lenL = mid-p+1;
    int lenR = r-mid;
    ///用动态数组分别保存两边的数
    int *L = new int[lenL+1];
    int *R = new int[lenR+1];
    /// 把元数组两边的书分别放进这个临时数组里面去
    for(int i = 0; i<lenL; i++)
    {
        L[i] = arr[p+i];
    }
    for(int j = 0; j<lenR; j++)
    {
        R[j] = arr[mid+j+1];
    }
    int i = 0, j = 0;
    for(int m = p; m<=r; m++)
    {
        if(L[i] < R[j])
        {
            arr[m] = L[i];
            i++;
        }
        else
        {
            arr[m] = R[j];
            j++;
        }
    }
}

