# Optimal Scheduling Strategies on Multi Processor Systems
 Under the guidance of Prof. Abhishek Mishra, we have attempted to find an Optimal Task Scheduling Strategy on Homogeneous Multi Processor Systems by considering the network of authors and their research papers during the period 2000-2018.<br /> Suggested and implemented Duplication based novel milp algorithm with various constraints, Exhaustive list scheduling (ELS), Allocation - Ordering algorithm (AO), and introduced various decision variables in Duplication based scheduling algorithm. <br />As a result of imposing constraints, schedule length is found to be increased indicating the tradeoff between constraints and the schedule length.
## Scope and Introduction:
Modern day applications are often implemented on multiprocessor systems i.e. tasks of the application are allocated to different processors for execution. As tasks are mapped to different processors, obtaining the optimal performance on multiprocessor systems remains challenging due to inter-processor communications between tasks of application. <br />To reduce this overhead incurred by inter-processor communications and improve the schedule performance, various strategies have been employed in the schedule.
## Inter-processor communications overhead:
When tasks of the application are mapped onto different processors for execution, inter-processor communications happens between these during execution, thereby increasing the scheduling length.<br /> The reasons includes two or more processors, requires same Resource (Contention Problem).<br /> To restrict the access, synchronisation occurs in the system for making the operations atomic and mutual exclusion. To tackle this overhead, task duplication strategy has been employed in the schedule.
## Existing Work
Scheduling is generally classified as three categories, list-based, cluster-based, duplication-based scheduling.<br /> List scheduling technique will assign various priorities, e.g., the s-level, b-level and t-level, to tasks during the scheduling.<br /> The tasks will be then ordered and scheduled as per the previously assigned priorities. Cluster based scheduling technique will bind tasks which most probably have large intercommunication as a cluster.<br /> This cluster is then scheduled on to the same processor. Therefore the tasks having the heavy inter – processor communication are now mapped on to the same processor and the schedule performance will be increased. Duplication-based scheduling, same tasks will be mapped to multiple processors for execution to reduce the schedule length.<br /> This approach used ILP for the non-duplication-based scheduling. This approach only focuses on reducing the communication cost, but the ordering and the data dependency and the timing constraints were not considered in this approach.
![image](https://user-images.githubusercontent.com/75213715/126064989-689320cf-677e-4aef-bf68-5d0e2c3a3456.png)

## Full-duplication strategy:
It duplicates immediate and indirect ancestors in a bottom-up fashion recursively.<br /> The various algorithms employing this strategy are listed below.<br />
i. The Critical Path Fast Duplication (CPFD) algorithm, tries to duplicate the very important parent into the available time slot of the processor until either the time slot is used up or the task start time is not improved any more.<br />
ii. The selective duplication (SD) algorithm, divided into three main steps, i.e. the task sequence generation phase, processor selection phase, and task assignment and duplication phase, was developed to improve the performance by selectively adding duplications of some tasks.<br />
iii. Drawbacks with Full Duplication<br /><br />
i. It has larger time complexity.<br />
ii. It incurs redundant duplications, which may increase the schedule length.<br />
a. Duplication-based Scheduling Algorithm Using Partial Schedules (DUPS):<br />
i. DUPS uses two stages. The schedule length is minimized by utilizing partial schedules in First phase; the number of processors required is minimized by eliminating and merging these partial schedules in the Second phase.<br />
ii. The Minimized Duplication at Joint node (MDJ) algorithm: Proposes concept of join node. It schedules join nodes without redundant duplications. In the algorithm, if the ancestor nodes of a join node are duplicated when scheduling the join node, the original allocations of these ancestor nodes are removed using a very efficient method.<br />
## Task Duplication Strategy:
The communication between tasks assigned to the same processor is considered negligible, whereas tasks allocated to different processors for execution, then, inter-processor communication is inevitable, which delays execution.<br /> Owing to the delay-free shared memory based intra-processor communication, i.e., local communication, part of inter-task communications are made local by allocating the task to multiple processors for execution. To be a delay free local communication, the source task is duplicated to the processor where the destination task is mapped to, thus removing the communication delay.<br /> Task duplication based scheduling algorithms generate shorter schedules without losing efficiency but leave the computing resources over consumed due to the heavily duplications of tasks.<br /> There are various issues with duplication strategy which can be listed as follows.<br />
## Issues with Duplication:
a. Which task(s) to be duplicated?<br />
b. How many times a task should be duplicated and where it should be duplicated?<br />
c. How should tasks on each processor be ordered and timed?<br />
d. How to determine the data precedence’s among duplications of a task and its successors?<br />
e. Finding the optimal duplication-based solution with the minimal schedule make span remains an issue.<br />
![image](https://user-images.githubusercontent.com/75213715/126064979-6ca4dda6-ad8b-4c2d-b0fa-b24f04c3c2ce.png)

## Mixed Integer Linear Programming Approach:
The MILP has been widely studied for the scheduling problem.<br /> Proposed an application-specific knowledge aware MILP for scheduling DAGs.In the formulation, the bi-linear equation is simplified to mitigate the size of the formulation.<br /> This paper proposes a novel Mixed Integer Linear Programming (MILP) formulation, together with a set of key theorems which enable and simplify the MILP formulation and solve the problem with optimality.<br /> This approach is guaranteed to be optimal in terms of schedule length for the duplication--based scheduling problem. <br />The task duplication is modeled appropriately using the task duplication variable in the formulation, thus resulting in optimal task duplication strategy.<br /> The reformulated data dependence is taken into account without a priori information about task duplication and mapping. A set of optimality theorems are summarized, which help to enable and simplify the modelling of the problem.<br />
A DAG is represented as G = (V, E), V is tasks; E is a finite set of directed edges denoting data precedence among tasks.<br /> Each task v ∈ V has computation cost c(v). Each edge e ∈ E is defined as a tuple (a, b), where a, b are source and destination tasks respectively. eab denotes the edge (a, b).<br /> Each edge e ∈ E has an integer communication cost w(e), which is the time taken for data transfer. <br />src(e), dst(e) represents source task and destination task , oe(v) are output edges and
succ(v) are successor tasks.<br /> Task without output is called the exit task, and the task without input edge or parent task is called the entry task of the DAG. <br />Vexit and Ventry represents sets of exit and entry tasks respectively and the number of processors are taken as P.<br /> Task-to-processor mapping map (v) and task start time Sv should be done during scheduling, f and sl are finish times and schedule lengths respectively.
## Proposed Optimality Theorems
### Lemma I.<br />
There is an optimal duplication-based schedule in which no more than one instance of the same task is duplicated to execute on the same processor. This ensures that each processor have a unique set of tasks.<br />
### Theorem I.<br />  
 There is an optimal duplication-based schedule in which each duplication of the destination task of an edge depends on the output data of one and only one duplication of the source task of the edge. <br />This says that there will be one to one dependency between source and destination tasks if at all dependency exist.
### Theorem II. <br />
There is an optimal duplication-based schedule in which each of the duplication of non-exit task feeds data to at least one duplication of its successors. <br />This ensures that there will be definite dependency between the source and the duplicated tasks among processors i.e. no useless executions taking place.<br />
 ### Theorem III. <br />
 There is an optimal duplication-based schedule in which: for any pair of different tasks a, b in the DAG, if task b is the only successor of task a, then the data precedence between a, b is obeyed by the partial schedule of the optimal schedule on each processor.<br />
 This says that though a, b tasks are mapped to different processors and there might be difference in execution time, but b will be mapped to some other task a on some processor thus satisfying the dependency.<br />
 This is represented as drtbk = fai + w(e) ≥ faj + w(e) + c(b) + c(a) + w(e), where the data ready time of bk is obtained by redirecting the input data of bk from ai to aj the new maximal data ready time of bk i<br />
 Redirecting the input data of bk from ai to aj , the new maximal data ready time of bk is drt′ bk = faj + w(e).<br />
### Theorem IV.<br />
There is an optimal duplication-based schedule in which the data precedence between the computation-dominated task (CDT) and all its successors are obeyed by the partial schedule of the optimal schedule on each processor.<br />
i. This means that though there can be more than one successor for a task mapped to a processor and its successors are mapped to different processors. <br />There can be difference in execution times between parent task and its successors but the successors will be mapped to some other duplication of parent task and the dependency will be preserved.<br />
ii. If one dependent task executes before source task, then logically, all its dependent tasks can be mapped to other source making the original source node redundant.
iii. For a Computationally Dominating Task, where it has one or more dependent tasks, the following equation holds in terms of computation cost and communication cost, for a given outgoing edge on a processor.<br />
C (v) + w (e1) + c (dst (e1)) ≥ w (e2), ∀e1, e2 ∈ oe (v), e1 ̸= e2<br />
### Duplication-based mixed integer linear programming formulation<br />
In the process of milp problem formulation, there are mainly two problem constraints which decide the entire schedule length.<br /> These constraints were carefully modelled such that every possible inter task dependency and inter task communications, order of task executions are carefully formulated. <br />The problem constraints to be imposed are as follows.<br />
a. Constraints on order of Task Execution.<br />
b. Constraints on Dependencies between Tasks.<br />
c. Objective Function which minimises the schedule length.<br />
## Constraints on the order of Task Execution:
These are the constraints which are imposed in order to define the timing of the execution of tasks.<br /> Tasks are categorised into various types like entry task, exit tasks, redundant tasks, source task which is the parent task and dependent tasks which depends on some source task during the order of their execution in the schedule. These can be mathematically formulated as follows.<br />
a. Entry task should execute only once.<br />
Xmi + Xmj = 1, ∀ m ∈ {a, b}<br />
b. Non entry task can be executed >= 1 times.<br />
Xvi + Xvj ≥ 1<br />
c. When a redundant duplication is found, its Start Time should be limited to zero i.e. the Redundant task never gets executed in the schedule.<br />
Smk ≤ M ∗ Xmk , ∀ m ∈ {a, b}, k ∈ P<br />
d. If both Source task and Dependent task are mapped to same processor, then their execution should be ordered i.e. Source task should execute before the Dependent task.<br />
fvk − Smk ≤ M ∗ (2 − Xvk − Xmk), ∀ m ∈ {a, b}, k ∈ P<br />
e. Since there are dependents to the task, the Finish time of the Source task and Start Times of the Dependent tasks should be ordered.<br />
fak − Sbk ≤ M ∗ (2 − Xak − Xbk ) + M ∗ Za,b,k, ∀ k ∈ P<br />
fbk − Sak ≤ M ∗ (2 − Xak − Xbk ) + M ∗ (1 − Za,b,k), ∀ k ∈ P<br /><br />
## Constraints on Dependencies between Tasks:
These constraints were imposed in order to order the dependencies, to avoid any unnecessary dependencies and redundant executions among tasks.<br /> There were four major dependency constraints in the milp formulation of our scheduling problem which are as follows.<br />
a. There should be at least one dependent successor task for a source task to be irredundant.<br />
dvkml ≤ Xvk , ∀ m ∈ {a, b}, k, l ∈ P<br />
b. Redundant dependencies should be removed as this result in redundant duplications.<br />
dviai + dviaj + dvibi + dvibj ≥ Xvi<br />
dvjai + dvjaj + dvjbi + dvjbj ≥ Xvj<br />
c. The successor dependent task should depend only on one source task in the schedule.<br />
dvimi + dvjmi = Xmi , ∀ m ∈ {a, b}<br />
dvimj + dvjmj = Xmj , ∀ m ∈ {a, b}<br />
d. Since tasks are dependent, the dependent task should start execution right after the finish time of the source task.<br />
fvi − Smi ≤ M ∗ (1 − dvimi ), ∀ m ∈ {a, b}<br />
fvj − Smj ≤ M ∗ (1 − dvjmj ), ∀ m ∈ {a, b}<br />
fvi + W(e1) − Saj ≤ M ∗ (1 − dviaj )<br />
fvj + W(e1) − Sai ≤ M ∗ (1 − dvjai )<br />
fvi + W(e2) − Sbj ≤ M ∗ (1 − dvibj )<br />
fvj + W(e2) − Sbi ≤ M ∗ (1 − dvjbi )<br />
## Objective Function:<br />
The main purpose in the problem of task scheduling is to reduce the schedule length.<br /> The schedule length in a schedule can be taken as the maximum of all finish times of tasks that exists in the schedule.<br /> Therefore the objective function can be mathematically formulated as follows.<br />
fmk ≤ SL, ∀ m ∈ {a, b}, k ∈ P<br />
## Execution Results: <br />
![image](https://user-images.githubusercontent.com/75213715/126064961-5f0e71f0-2212-48bf-af50-d2ed222739e8.png)

The sample Task Graph for execution is chosen having 9 tasks which are interdependent.

![image](https://user-images.githubusercontent.com/75213715/126064936-983f22aa-50df-4f95-924d-8523cf6a7405.png)

![image](https://user-images.githubusercontent.com/75213715/126064926-6171d656-f46b-4806-8829-14f82e14da02.png)


