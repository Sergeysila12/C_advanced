#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  2
double DELAY = 0.1;
#define PLAYERS 3


enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=4, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10,SEED_NUMBER=3   , CONTROLS=3};


// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
}control_buttons;


struct control_buttons default_controls[CONTROLS]={
			{KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT},
			{'S', 'W', 'A', 'D'},  
			{'s', 'w', 'a', 'd'}  
};



/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
   struct control_buttons controls;
   _Bool is_ai;
   // struct control_buttons* controls[];
    
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;

struct food
{
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];



	int distance(const snake_t snake, const struct food food) 
		{ // вычисляет количество ходов до еды
			return (abs(snake.x - food.x) + abs(snake.y - food.y));
		}
void autoChangeDirection(snake_t *snake, struct food food[], int foodSize)
{
	int pointer = 0;
	for (int i = 1; i < foodSize; i++) 
	{ // ищем ближайшую еду
		pointer = (distance(*snake, food[i]) < distance(*snake, food[pointer])) ? i : pointer;
	}
	if ((snake->direction == RIGHT || snake->direction == LEFT) &&
		(snake->y != food[pointer].y)) { // горизонтальное движение
		snake->direction = (food[pointer].y > snake->y) ? DOWN : UP;
	} 
	else if ((snake->direction == DOWN || snake->direction == UP) &&
 (snake->x != food[pointer].x)) { // вертикальное движение
 snake->direction = (food[pointer].x > snake->x) ? RIGHT : LEFT;
 }
}



_Bool haveEat(snake_t *head, struct food f[], int nfood)
{
    //...нужно написать код...//
    
    for (size_t i = 0; i < nfood; i++)
	{
		if (f[i].enable&&head->x==f[i].x&&head->y==f[i].y)
		{
			f[i].enable=0;
			return 1;
		}
		
	}
    
    return 0;
}

void addTail(struct snake_t *head)
{
    //...нужно написать код...//
    if (head->tsize <= MAX_TAIL_SIZE)
	{
		 head->tsize++;
	}
   
    
}

void initFood(struct food f[], size_t size)
{
    struct food init = {0,0,0,0,0};
    for(size_t i=0; i<size; i++)
    {
        f[i] = init;
    }
}
/*
 Обновить/разместить текущее зерно на поле
 */
void putFoodSeed(struct food *fp)
{
    int max_x=0, max_y=0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (max_x - 1);
    fp->y = rand() % (max_y - 2) + 1; //Не занимаем верхнюю строку
    fp->put_time = time(NULL);
    fp->point = '$';
    fp->enable = 1;
    spoint[0] = fp->point;
    mvprintw(fp->y, fp->x, "%s", spoint);
}

/*
 Разместить еду на поле
 */
void putFood(struct food f[], size_t number_seeds)
{
    for(size_t i=0; i<number_seeds; i++)
    {
        putFoodSeed(&f[i]);
    }
}

void refreshFood(struct food f[], int nfood)
{
    for(size_t i=0; i<nfood; i++)
    {
        if( f[i].put_time )
        {
            if( !f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS )
            {
                putFoodSeed(&f[i]);
            }
        }
    }
}

void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t={0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}
void initHead(snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}

//void initSnake(snake_t *head, size_t size, int x, int y)
void initSnake(snake_t *head[], size_t size, int x, int y,int i, _Bool is_ai)
{
	 head[i]    = (snake_t*)malloc(sizeof(snake_t));
	tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head[i], x, y);
    head[i]->tail = tail; // прикрепляем к голове хвост
    head[i]->tsize = size+1;
    head[i]->controls = default_controls[i % CONTROLS];
    head[i]->is_ai = is_ai; 
}
int checkDirection(snake_t * snake, int32_t key)
{
    if (key == STOP_GAME) return 0;
    
    int new_direction = -1;
    int old_direction = snake->direction;
    
    
    if (key == snake->controls.down) new_direction = DOWN;
    else if (key == snake->controls.up) new_direction = UP;
    else if (key == snake->controls.left) new_direction = LEFT;
    else if (key == snake->controls.right) new_direction = RIGHT;
    
    if (new_direction == -1) return 0; // Кнопка не из схемы управления
    
    // Запрет разворота на 180°
    if ((new_direction == DOWN && old_direction == UP) ||
        (new_direction == UP && old_direction == DOWN) ||
        (new_direction == LEFT && old_direction == RIGHT) ||
        (new_direction == RIGHT && old_direction == LEFT))
        return 0;
    
    return 1; // Можно менять направление
}
/*
 Движение головы с учетом текущего направления движения
 */
void go(snake_t *head)
{
    char ch = '@';
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ
    switch (head->direction)
    {
        case LEFT:
            if(head->x <= 0)head->x = max_x-1; // Циклическое движение, чтобы не // уходить за пределы экрана
            mvprintw(head->y, --(head->x), "%c", ch);
        break;
        case RIGHT:
			if(head->x >= max_x)head->x =0;
            mvprintw(head->y, ++(head->x), "%c", ch);
        break;
        case UP:
			if(head->y <= 0)head->y =max_y-1;
            mvprintw(--(head->y), head->x, "%c", ch);
        break;
        case DOWN:
			if(head->y >= max_y)head->y =MIN_Y;
            mvprintw(++(head->y), head->x, "%c", ch);
        break;
        default:
        break;
    }
    refresh();
}




/*
 Движение хвоста с учетом движения головы
 */
void goTail( snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}
void changeDirection(snake_t* snake, const int32_t key)
{
    if (key == snake->controls.down)
        snake->direction = DOWN;
    else if (key == snake->controls.up)
        snake->direction = UP;
    else if (key == snake->controls.right)
        snake->direction = RIGHT;
    else if (key == snake->controls.left)
        snake->direction = LEFT;
}
void update(snake_t *snake, struct food f[], const int32_t key_pressed)
{
	 clock_t begin = clock();
	 
	 if (snake->is_ai)autoChangeDirection(snake,f,SEED_NUMBER);
	 
	    go(snake);
        goTail(snake);
    //    timeout(100); // Задержка при отрисовке
 //   checkDirection(snake, key_pressed);

        
		if (haveEat(snake,food, SEED_NUMBER)) //ПРОВКРКА НА СЪЕДЕНИЕ
        {
            addTail(snake);
        }

      //  key_pressed=checkDirection(snake, key_pressed); 
		refresh();//Обновление экрана, вывели кадр анимации
	while ((double)(clock() - begin)/CLOCKS_PER_SEC<DELAY){}
	
}

_Bool isCrush(snake_t * snake)
{
    //...нужно написать код...//
    
    for (int i = 2; i < snake->tsize; i++)
		{
			if(((snake->tail[i].x)==snake->x)&&((snake->tail[i].y)==snake->y)) {return 1;}
		}
    return 0;
}

void repairSeed(struct food f[], size_t nfood, snake_t *head)
{
	size_t i;
    for( i=0; i<head->tsize; i++ ){
        for( size_t j=0; j<nfood; j++ )
        {
            /* Если хвост совпадает с зерном */
            //...нужно написать код...//
            if (f[j].enable&&f[j].x==head->tail[i].x&&f[j].y==head->tail[i].y)
			{
				f[j].enable=0;
				mvprintw(f[j].y, f[j].x, " ");
			}
            
        }
	}
        
    for(i=0; i<nfood; i++ )
		if (!f[i].enable) continue;
        for( size_t j=0; j<nfood; j++ )
        {
            /* Если два зерна на одной точке */
            //...нужно написать код...//
            if (i!=j && f[j].enable && f[j].x == f[i].x && f[j].y ==f[i].y)
			{
				f[i].enable=0;
				mvprintw(f[j].y, f[j].x, " ");
			}
        }
        refresh();
}



int main()
{
//snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
//========================================================================   
int is_ai=0;
snake_t* snakes[PLAYERS];
    for (int i = 0; i < PLAYERS; i++)
    {
		if (i==2)is_ai=1;
        initSnake(snakes,START_TAIL_SIZE,10+i*10,10+i*10,i,is_ai);
	}
//========================================================================

  //  initSnake(snake,START_TAIL_SIZE,10,10);
    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    mvprintw(0, 0,"Use arrows for control. Press 'F10' for EXIT");
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    
    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);// Кладем зерна
    int key_pressed=0;
    while( key_pressed != STOP_GAME )
    {
        key_pressed = getch(); // Считываем клавишу
        for (int i = 0; i < PLAYERS; i++)
		{
			if (checkDirection(snakes[i], key_pressed))
			{
				changeDirection( snakes[i], key_pressed);
			}
		update(snakes[i], food, key_pressed);
        if (isCrush(snakes[i]))
			{
				key_pressed=STOP_GAME;
				break;
			}
		 repairSeed(food, SEED_NUMBER, snakes[i]);
		 refreshFood(food, SEED_NUMBER);// Обновляем еду
		}
  
    }
    for (int i = 0; i < PLAYERS; i++)
	{
		free(snakes[i]->tail);
		free(snakes[i]);
	}
    endwin(); // Завершаем режим curses mod
    return 0;
}
