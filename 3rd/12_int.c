//表示输入输出头文件
#include <stdio.h>
//str家族函数头文件 strcpy strcat strcmp strchr strlen memcpy ...
#include <string.h>
//申请内存空间头文件 malloc calloc realloc
#include <stdlib.h>


#define MAX 10

//定义学生结构体类型
struct cls_t{
	char name[64];
	int age;
	int id;
	char sex;
	float cn;
	float en;
	//=======
};

//函数声明
//实现插入    新的数据   旧的数据   数据长度    数据类型（大小）
void *insert(void *cls, void *prev, int *count, int size);


int main(void)
{
	int i;
	int count = 0;
	int num;
	struct cls_t cls;
	/*struct cls_t *new = NULL;*/
	int *new = NULL;
	struct cls_t *prev = NULL;
	//rand() 随机数
	//int snprintf(char *str, size_t size, const char *format, ...);
	// 第一个参数：表示空间地址
	// 第二个参数：表示空间大小
	// 第三个参数：表示格式 %s %d %c %f %p %x ...
	// ...		   表示可变参 对格式补充	
	for (i = 0; i < MAX; i++)
	{
		//获取数据
        /*
		 *snprintf(cls.name, sizeof(cls.name), "cls_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
		 *cls.age = rand() % 3 + 18;
		 *cls.id = rand() % 100 + 10000;
		 *cls.sex = "MF"[rand() % 2];
		 *cls.cn = rand() % 30 + 70;
		 *cls.en = rand() % 20 + 80;
         */

		num = rand() % 100;
		//插入函数实现 函数调用
		new = insert(&num, new, &count, sizeof(int));

/*
 *        //申请空间
 *        new = (struct cls_t *)malloc(sizeof(struct cls_t) * (count + 1));
 *        if (new == NULL)
 *        {
 *            return -1;
 *        }
 *
 *        //数据保存到空间中
 *        memcpy(new, prev, sizeof(struct cls_t) * count);
 *        free(prev);
 *        *(new + count) = cls;
 *        prev = new;
 *
 *
 *        count++;
 */
        /*
		 *printf("name : %s age : %d id : %d sex : %c cn : %.2f en : %.2f\n", 
		 *    cls.name, cls.age, cls.id, cls.sex, cls.cn, cls.en);
         */
	}

	//遍历
	for (i = 0; i < MAX; i++)
	{
		/*printf("name : %s | age : %d | sex : %c\n", new[i].name, new[i].age, new[i].sex);*/
		printf("%d ", new[i]);
	}
	printf("\n");
		
	//销毁	
	free(new);
	return 0;
}


//函数实现
void *insert(void *data, void *prev, int *count, int size)
{
	void *new = NULL;

	//申请空间
	/*new = (struct cls_t *)malloc(sizeof(struct cls_t) * (*count + 1));*/
	new = (void *)malloc(size * (*count + 1));
	if (new == NULL)
	{
		return NULL;
	}

	//数据保存到空间中
	memcpy(new, prev, size * (*count));
	free(prev);
	memcpy(new + (*count) * size, data, size);
	/**(new + (*count)) = cls;*/

	(*count)++;
	return new;
}
