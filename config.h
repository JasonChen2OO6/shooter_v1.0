#ifndef CONFIG_H
#define CONFIG_H

#define WIN_W 1280
#define WIN_H 960

#define PLY_SIZE 40
#define ENM_SIZE 20
#define BLT_SIZE 10

#define EENM_SIZE 40

#define ENM_RPS 1       // repulsion
#define ENM_RPL 2000
#define ENM_PRPS 10
#define EENM_PRPS 30
#define ENMB_CLR_RG 200 // enemy bullet clear range

#define BLT_SPEED 10

#define ENM01_M 1.5
#define ENM01_V 2000    // velocity
#define ENM01_H 1       // health
#define ENM01_A 1       // attack
#define ENM01_E 1       // experience

#define ENM02_M 1
#define ENM02_V 2000    // velocity
#define ENM02_H 1       // health
#define ENM02_A 1       // attack
#define ENM02_E 2       // experience

#define ENM03_M 3
#define ENM03_V 3000    // velocity
#define ENM03_H 3       // health
#define ENM03_A 1       // attack
#define ENM03_E 5       // experience
#define ENM03_I 300     // interval
#define ENM03_BV 3      // bullet velocity

#define EENM01_M 10
#define EENM01_V 5000    // velocity
#define EENM01_H 3       // health
#define EENM01_A 1       // attack
#define EENM01_E 5       // experience
#define EENM01_I 500     // interval
#define EENM01_BV 2      // bullet velocity

const int levelUps[21] = {10, 20, 30, 40, 50, 70, 90, 110, 140, 170,
                          200, 240, 280, 320, 380, 440, 500, 600, 800, 1000, 1000};

const int intervals[6] = {0, 100, 80, 60, 40, 20};

const float velocities[6] = {0, 0.2, 0.3, 0.4, 0.5, 0.6};

const int attacks[6] = {0, 1, 2, 3, 4, 5};

const int bulletSizes[6] = {0, 10, 15, 20, 25, 30};


#endif // CONFIG_H
