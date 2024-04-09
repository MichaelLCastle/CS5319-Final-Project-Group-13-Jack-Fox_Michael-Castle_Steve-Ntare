# Red Rock National Conservatory Visitor Center Servicce

By: Jack Fox, Steve Ntare, and Michael Castle. 

## How to compile and execute our code

This project was creating using the CLion IDE and CMake. To implement the code, follow the steps below:

### 1) Clone the repository

Run the following in your local terminal:`git clone https://github.com/MichaelLCastle/CS5319-Final-Project-Group-13-Jack-Fox_Michael-Castle_Steve-Ntare.git`

### 2) Open the project using CLion

Using the CLion IDE, open the project wherever it was cloned in your local machine.  

### 3) Setting up CMake

This project was implemented using CMake version 3.21 which must he installed on your local machine. After opening the project in CLion, the IDE should automatically create a cmake-build-debug directory based on the CMAkeList.txt file provided.

After the cmake-build-debug directory has been created, the .csv files held in the tables directory need to be copied into the cmake-build-debug directory. This is to allow the program to access the files on your local machine. 

### 4) Configuring CLion

The last step in setting up our project is configuring the CLion IDE to recognize and run our project. To do this, click on the edit configuration button in the top right. Ensure that CLion is using Final_NationalPark as the target and executable. 

### 5) Executing the project

After all the previous steps have been completed, the project is ready to execute. Using the CLion IDE, the project can easily be executed using the run button in the top right corner.

## Implementation differences

Scalability and flexibility provided by the Client-Server model are crucial for handling the increasing number of park visitors and the guide's expanding content. Through centralized databases and servers, it makes it easier to update park information, trail guides, and news without interfering with client-side applications. This degree of flexibility is absent from the Pipe and Filter architecture, which makes updates and scaling more difficult and less efficient due to its series of fixed processing stages. This is due to the Pipe and Filter model's data flowing through a series of components (filters) in a defined sequence where each filter processes the data and passes it to the next one in the pipeline.

## Reusable Components/Connectors

Reusable Connectors in both models:

Database Interactions (Connector):
The methods for loading (load_*), saving (save_*), adding (add_*), and getting (get_*) information are connectors that interact with the database. These methods can be reused for different data types and across multiple components.

User Authentication (Connector):
Functions related to user authentication such as login() and Authentication(database) are designed to be reusable across the system wherever user authentication is required.

API Calls (Connector):
The method callChatGPTAPI() or and the  can be reused wherever external API integration is required.

Reusable Components in the Pipe and Filter Model:

Filters (Components):

NewsAndBasicParkInformationFilter, FeedbackFilter, AIHelpFilter: These filters encapsulate specific functionalities and could be reused in different contexts within the application or even across different applications.

Reusable Components in the Client-Server Model:

Pages (Components):

ActivitiesPage, FeedbackPage, BasicParkInformationPage, HomeScreen, AIHelperPage: Each page encapsulates the logic required for a specific part of the application and could be reused or extended as needed.

