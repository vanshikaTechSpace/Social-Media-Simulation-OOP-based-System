# Social Media Simulation

This is a simple C++ simulation of a social media platform. The program demonstrates basic object-oriented programming concepts, such as classes and methods, by simulating user interaction within a social media environment.

## Features

- **User Accounts**: Create new user accounts with a username and password.
- **Post Creation**: Users can create posts.
- **Timeline View**: Users can view their timeline, showing posts they've created.
- **File Handling**: User data is saved to and loaded from a text file (`record.txt`).

## Classes

### `User`
Represents an individual user in the social media simulation. Each user has a username and can create posts.

### `Post`
Represents a post created by a user. Each post contains content and the author's name.

### `SocialMedia`
Handles the overall simulation, including user management and the interaction between users and their posts.

## How to Run the Program

1. **Clone the Repository**:
    ```sh
    git clone https://github.com/your-username/Social-Media-Simulation.git
    cd Social-Media-Simulation
    ```

2. **Compile the Program**:
    ```sh
    g++ -o social_media_simulation main.cpp
    ```

3. **Run the Program**:
    ```sh
    ./social_media_simulation
    ```

## Example Usage

1. **Create a New User Account**: 
   The program will prompt you to enter a username and password. After that, the new user account will be created.

2. **Create a Post**:
   After logging in, you can create a new post by entering the content.

3. **View Timeline**:
   Users can view their timeline, which displays all the posts they have created.

## File Handling

- The program uses `record.txt` to store user data, including usernames and passwords. This file is automatically created if it doesn't exist and is updated whenever a new user is created or data is saved.

## Contributing

Contributions are welcome! Feel free to fork this repository and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

For any questions or suggestions, feel free to reach out:

- **Email**: aryan.cs.22@nitj.ac.in
- **GitHub**: https://github.com/ARYAN-ark-1/

---

Happy Coding!
