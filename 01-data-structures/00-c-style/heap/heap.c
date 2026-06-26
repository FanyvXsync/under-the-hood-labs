#include "heap.h"

void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->a = php->capacity = 0;
}

void HPDestory(HP* php)
{
	assert(php);
	free(php->a);
	free(php);

	php = NULL;
}

void Swap(HPDateType* s1, HPDateType s2)
{
	HPDateType* tmp = s1;
	s1 = s2;
	s2 = tmp;
}

void AdjustUp(HPDateType* a, int child)  // 没传堆， 后面说.
{

	int parent = (child - 1) / 2;  // 传下标奥
	// 初始条件 中间过程 结束条件，  控制好了，循环就好了
	// 结束条件 两个，一个是到根，一个是比孩子小了
	// 但是时时刻刻记住，逻辑上是二叉树，物理上是数组，这里还是下标控制
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			// 更新下标

			child = parent;
			parent = (child - 1) / 2;  // 用parent >= 0 ,不太行 ，parent 不会小于零 整除的问题  但是有个巧合 会走 break;
		}                              // 所以，用child ， 当然这里不止这一种写法
		else
		{
			break;
		}
	}

}

void HPPush(HP* php, HPDateType x)
{

	assert(php);

	if (php->size == php->capacity)
	{
		int newcapcity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDateType* new = (HPDateType*)realloc(php->a, newcapcity * sizeof(HPDateType));
		
		if (new == NULL)
		{
			perror("malloc failed");
			return;
		}

		php->a = new;
		php->capacity = newcapcity;

	}

	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);

}

void AdjustDown(HPDateType* a, int parent, int n)
{
	// 假设法 ******  有可能左孩子小，有可能右孩子小，假设左孩子小
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])  //child + 1 要判断
		{
			child++;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
		
}

void HPPop(HP* php)  // pop删除要求删除堆顶的数据，（根位置） 肯定不能直接挪动数据，
{						//删除了以后数据不一定还是堆，关系就乱了
	assert(php);				// 把对顶的元素和最后一个换一下，这样左右子树还是堆，然后向下调整，删除只需要
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size - 1]);						// 向下调整前提左右子树都是堆噢
									// 这样不断 pop是不是就有序了，每次都把最小的换到对顶，可以认为这是堆排序的前身
	AdjustDown(php->a, 0, php->size);								// 没有孩子了，就到叶子了，超出数组范围
}
                                    // 在堆排之前，不断pop就是打印有序
									// 也可以找出最大的前 k 个， TopK 的前身

HPDateType HPTop(HP* php)
{
	assert(php);				
	assert(php->size > 0);

	return php->a[0];
}

bool HPEmpty(HP* php)
{
	assert(php);
	return php->size;
}


// 注意奥，这里只是打印有序，并没有让 测试的数组有序
// 想让测试的数组有序，只要把 pop了的元素往数组里面放不就好了  但是这个方法排序不好，因为空间复杂度是 O(N); 