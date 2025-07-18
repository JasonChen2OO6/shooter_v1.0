#ifndef CONFIG_H
#define CONFIG_H

#define WIN_W 1280
#define WIN_H 960

#define BLT_SPEED 10

#define PLY_SIZE 40
#define BLT_SIZE 10
#define PTC_SIZE 10

#define ENM_RPS 1       // repulsion
#define ENM_RPL 2000
#define ENM_PRPS 10
#define EENM_PRPS 30
#define ENMB_CLR_RG 200 // enemy bullet clear range

#define ENM01_S 20
#define ENM01_M 1.5
#define ENM01_V 2000    // velocity
#define ENM01_H 1       // health
#define ENM01_A 1       // attack
#define ENM01_E 1       // experience

#define ENM02_S 20
#define ENM02_M 1
#define ENM02_V 2000    // velocity
#define ENM02_H 1       // health
#define ENM02_A 1       // attack
#define ENM02_E 2       // experience

#define ENM03_S 20
#define ENM03_M 3
#define ENM03_V 3000    // velocity
#define ENM03_H 3       // health
#define ENM03_A 1       // attack
#define ENM03_E 5       // experience
#define ENM03_I 300     // interval
#define ENM03_BV 3      // bullet velocity

#define EENM01_S 40
#define EENM01_M 10
#define EENM01_V 5000    // velocity
#define EENM01_H 3       // health
#define EENM01_A 1       // attack
#define EENM01_E 5       // experience
#define EENM01_I 500     // interval
#define EENM01_BV 2      // bullet velocity

#define BOSS01_S 60
#define BOSS01_M 50
#define BOSS01_V 0.02
#define BOSS01_H 1000
#define BOSS01_A 2
#define BOSS01_E 100
#define BOSS01_I 10
#define BOSS01_MI 500
#define BOSS01_BV 1

#define BOSS02_S 80
#define BOSS02_M 1000
#define BOSS02_V 0.02
#define BOSS02_H 10000
#define BOSS02_A 3
#define BOSS02_E 114514
#define BOSS02_I 5
#define BOSS02_MI 1000
#define BOSS02_BV 3

#define SENM_S 80
#define SENM_M 1000
#define SENM_V 0.02
#define SENM_H 50
#define SENM_A 2
#define SENM_E 0
#define SENM_I 250
#define SENM_MI 1000
#define SENM_BV 1
#define IVCB_TIME 100    //invincible time
#define SPLSH_RG 150     // splash range
#define MAX_BNC_TIME 4   // max bounce time
#define MAX_RTD_TIME 400 // max retard time
#define RTD_RATE 0.5     // retard rate
#define MAX_IVCB_TIME 400// max invincible time



const int levelUps[21] = {10, 20, 30, 40, 50, 70, 90, 110, 140, 170,
                          200, 240, 280, 320, 380, 440, 500, 600, 800, 1000, 1000};

const int intervals[6] = {0, 100, 80, 60, 40, 20};

const float velocities[6] = {0, 0.2, 0.3, 0.4, 0.5, 0.6};

const int attacks[6] = {0, 1, 2, 3, 4, 5};

const int bulletSizes[6] = {0, 10, 15, 20, 25, 30};

const int repelForces[6] = {0, 1000, 1500, 2000, 2500, 3000};

#endif // CONFIG_H
