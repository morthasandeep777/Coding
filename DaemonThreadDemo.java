class DaemonThreadExample extends Thread {
    public void run() {

        if (isDaemon()) {
            System.out.println("This is a daemon thread.");
        } else {
            System.out.println("This is a user thread.");
        }

        for (int i = 1; i <= 5; i++) {
            System.out.println(getName() + " - Count: " + i);
            try {
                Thread.sleep(1000); 
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
        System.out.println(getName() + " finished execution.");
    }
}

class DaemonThreadDemo {
    public static void main(String[] args) {
        DaemonThreadExample daemonThread = new DaemonThreadExample();
        DaemonThreadExample userThread = new DaemonThreadExample();

        daemonThread.setDaemon(true);

        daemonThread.start();
        userThread.start();

        System.out.println("Main thread is finished.");
    }
}
