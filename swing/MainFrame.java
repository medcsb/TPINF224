package swing;

import javax.swing.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainFrame extends JFrame {
    private JTextArea responseTextArea;
    private JTextField searchField;
    private JButton searchButton;
    private JButton playButton;

    private Client client;

    public MainFrame() {
        // Initialize the Client
        try {
            client = new Client("localhost", 3331);
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }

        // Create UI elements
        responseTextArea = new JTextArea(10, 40);
        searchField = new JTextField(20);
        searchButton = new JButton("Search");
        playButton = new JButton("Play");

        // Add actions to buttons
        searchButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String query = searchField.getText();
                String response = client.send("SEARCH:" + query);
                responseTextArea.setText(response);
            }
        });

        playButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String selectedItem = responseTextArea.getSelectedText();
                if (selectedItem != null) {
                    String response = client.send("PLAY:" + selectedItem);
                }
            }
        });

        // Create layout and add components
        JPanel mainPanel = new JPanel();
        mainPanel.add(new JScrollPane(responseTextArea));
        mainPanel.add(searchField);
        mainPanel.add(searchButton);
        mainPanel.add(playButton);

        // Add mainPanel to JFrame
        add(mainPanel);

        // Set JFrame properties
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new MainFrame());
    }
}
