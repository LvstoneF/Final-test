
void Mergesort(int arr[], int p, int r)
{
    /*
    1. p: �������ָ��
    2. r: βָ��
    3. һ���ϲ����������Ҫ�Ȱ�һ������ֳ������������֣�
    4. Ȼ���ڰ������������ֹ鲢
    */
    if(p<r){
        int mid = ((r+p)/2);
        Mergesort(arr[], p, mid);//�����벿��
        Mergesort(arr[], mid+1, r); // ����Ұ벿��
        Merge(arr[], p, mid, r);
    }
}



void Merge(int arr[], int p, int mid, int r)
{
    int lenL = mid-p+1;
    int lenR = r-mid;
    ///�ö�̬����ֱ𱣴����ߵ���
    int *L = new int[lenL+1];
    int *R = new int[lenR+1];
    /// ��Ԫ�������ߵ���ֱ�Ž������ʱ��������ȥ
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

