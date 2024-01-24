#include <stdio.h>
#include <stdlib.h>

int **lruc;

int find_pr_loc(int pr_id)
{
    int loc =-1, i=0;
    for(i=0; i<=5;i++)
    {
        if(lruc[0][i]==pr_id)
        {
            loc = i;
        }
    }
    return loc;
}

int is_id_present(int pr_id)
{
    if(find_pr_loc(pr_id) > 0)
        return 1;
    else 
        return 0;
}

int get_pr_val(int pr_id)
{
    int val;
    val = lruc[1][find_pr_loc(pr_id)];

    return val;
}

int pr_val_input(void)
{
    int val;
    printf("Enter value= ");
    scanf("%d",&val);
    return val;
}

void rearrange_cache(int loc)
{
    int temp_id =lruc[0][loc];
    int temp_val =lruc[1][loc];

    for(int i = loc; i<4; i++)
    {
        lruc[0][i]=lruc[0][i+1];
        lruc[1][i]=lruc[1][i+1];
    }
}
void print_id_val(void)
{
    printf("Loc\t Id\t Val\n");
    for(int i=0;i<5;i++)
        printf("%d \t%d \t %d\n", i, lruc[0][i], lruc[1][i]);
}

int main()
{
    int pr_id;
    int loc, chg_val_flg;
    int temp_id=0;
    int temp_val =0;
    
    printf("\nProgram to implement LRU Cache\n\n");
    printf("\nThe Cache has \n -5 location\n -5 id \n -5 Value\n\n");
    lruc =(int**) malloc(2*sizeof(int*));
    for(int i=0;i<2;i++)
        lruc[i] = (int*) malloc(5*sizeof(int));

    while(1)
    {
        print_id_val();
        printf("\nEnter the Process Id= ");
        scanf("%d", &pr_id);

        loc = find_pr_loc(pr_id);
        temp_id = pr_id;
        if(loc<0)
        {
            int val;
            val = pr_val_input();
            temp_val = val;
            loc = 0;
        }
        else 
        {
            printf("\nId= %d Change Val 1/0? = ",pr_id);
            scanf("%d", &chg_val_flg);
            if(chg_val_flg)
                temp_val = pr_val_input();
            else
                temp_val = get_pr_val(pr_id);
        } 
        rearrange_cache(loc);
        lruc[0][4]= temp_id;
        lruc[1][4]= temp_val;
        print_id_val();
    }

    return 0;
}
