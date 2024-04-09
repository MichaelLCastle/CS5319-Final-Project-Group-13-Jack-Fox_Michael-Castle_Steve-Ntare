# Red Rock National Conservatory Visitor Center Servicce

By: Jack Fox, Steve Ntare, and Michael Castle. 

## How to implement platform

This project was creating using the CLion IDE and 

## How to compile code

## How to execute system

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

