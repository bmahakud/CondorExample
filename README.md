All Instructions here

in any of the directory inside your lpc do 
```
git clone https://github.com/bmahakud/CondorExample
```
So this set will enable you to run submit a job to condor. If you want to run the code interactively you can do

```
root -l TriggerCheck.C+
```
You will see after running the code , there is a output root file . Now if you want to do this task using condor and send the out put root file to your eos area , first you need to change the output path in side the file 

jobExecCondor.jdl

root://cmseos.fnal.gov//store/user/bmahakud/OutputFile

replace this with yours. Now submit the job using 
```
condor_submit jobExecCondor.jdl
```

To check the status of job do

```
condor_q username

```
here username is your username

Once the jobs are done see your output directory




