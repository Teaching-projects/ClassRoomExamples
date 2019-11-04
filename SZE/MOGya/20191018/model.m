param nJobs;
param nWorkers;

set Jobs := 1..nJobs;
set Workers := 1..nWorkers;

param required_skill{Jobs};
param duration{Jobs};

param skill_level{Workers};
param salary{Workers};
param availability{Workers};

var do{Jobs,Workers} binary;

s.t. SkillLevelConstraint
  #Ha a worker gyenge,ne csinalhassa meg a jobot
  #Ha a worker gyenge, akkor do[j,w]=0;
  #Ha skill_level[w]<required_skill[j] akkor do[j,w] = 0
{j in Jobs, w in Workers: skill_level[w]<required_skill[j]}:
  do[j,w] = 0;

s.t. WorkAsMuchAsAvailability{w in Workers}:
  sum {j in Jobs} duration[j] * do[j,w] <= availability[w];

s.t. DoAllJobs{j in Jobs}:
  sum{w in Workers} do[j,w] = 1;

minimize Cost:
  sum{w in Workers, j in Jobs} salary[w]*duration[j]*do[j,w];


solve;

for {w in Workers}
{
  printf "Worker %d:\t%g/%g\n",w,sum{j in Jobs:do[j,w]==1}duration[j],availability[w];
  for {j in Jobs : do[j,w]==1}
    printf " - Job %d\t%g\n",j,duration[j];
  printf "\n";
}

  
