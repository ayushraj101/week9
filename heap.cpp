#include<iostream>
using namespace std;

class heap 
	{
		public:
		int *hArr;
		int csize, msize;
		heap(int xsize)
			{
				hArr = new int[msize];
				csize = -1;
				xsize = msize; 
			}
		void Swap(int i, int j)
			{
				int temp = hArr[i];
				hArr[i] = hArr[j];
				hArr[j] = temp;
			}
		int parent(int i)
			{
				return (i-1)/2;
			}
		int left (int i)
			{
				return (i*2)+1;
			}
		int right (int i)
			{
				return (i*2)+2;
			}
		int getMin()
			{
				return hArr[0];
			}
		void insert (int value)
			{
				if(csize >= msize-1) cout<< "The heap is full. ";//condition for heap overflow
				else
					{
						csize++;
						hArr[csize] = value;//insert new key at end
						minHipifyU(csize);//call hepify function
					}
			}
		void display()
			{
				for(int i =0; i <= csize; i++ )
					{
						cout<< hArr[i] <<" -> " ;
					}
				cout<<"NULL"<< endl;
			}
		int exmin()
			{
				if(csize == -1) cout<< "The heap is empty \n";//base for empty heap
				else if(csize == 0)//basecase for heap with one value
					{
						int temp = hArr[0];
						csize--;
						return temp;
					}
				else
					{
						int temp = hArr[0];
						hArr[0] = hArr[csize];//copy last element to the root
						csize--;
						minHipifyD(0);//hepify
						return temp;//return root
					} 
			}
		void deckey(int i, int value)
			{
				if(i > csize) cout << "The index is out of the heap\n";
				else
					{
						hArr[i] = value;
					}
			}
		void delkeyat(int i)
			{
				hArr[i] = hArr[csize];
				csize--;
				minHipifyD(i);
			}
		void minHipifyD(int i)
			{
				//cout<<"csize is "<<csize<< endl;
				if(i < csize)
				{
					if(hArr[left(i)]>hArr[right(i)] and right(i)< csize)
						{
							int temp = hArr[right(i)];//compare for eft and right
							if (temp < hArr[i]) Swap (i,(i*2)+2);//replace with smallest
							minHipifyD((i*2)+2);//call minhipyfy to right
					
						}
					else if (left(i)<csize and hArr[left(i)]<=hArr[right(i)])
						{
							int temp = hArr[left(i)];
							if(temp < hArr[i]) Swap (i,(i*2)+1);
							minHipifyD((i*2)+1);//call minheapify to left
						}
						
					}
			}
		void minHipifyU(int i)
			{
				if(i>0 and hArr[i] < hArr[(i-1)/2])
				{
					Swap(i, (i-1)/2);
					minHipifyU((i-1)/2);
				}
				/*for (;i <0 and hArr[i] < hArr[(i-1)/2] ;(i-1)/2)
					{
						Swap()
					}*/			
			}	
		};
	
int main ()
	{
		heap bh1(20);
    for(int i = 10; i >0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
        bh1.display();
    }
    bh1.exmin();
    bh1.display();
    bh1.delkeyat(3);
    bh1.display();
    cout << endl;
		return 0;
	}
