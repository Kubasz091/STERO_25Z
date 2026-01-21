import pandas as pd
import matplotlib.pyplot as plt
import sys
import numpy as np

def main():
    if len(sys.argv) < 2:
        file_path = "square_mover_data.csv"
    else:
        file_path = sys.argv[1]

    try:
        df = pd.read_csv(file_path)
    except FileNotFoundError:
        print(f"Error: File {file_path} not found.")
        return

    # Check for required columns
    required_cols = ['time', 'pos_err_sq', 'orient_err_sq']
    if not all(col in df.columns for col in required_cols):
        print(f"Error: CSV is missing one of the required columns: {required_cols}")
        return

    print("\n=== SYSTEM REPORT ===")
    print(f"Total Data Points: {len(df)}")
    
    # Calculate derived metrics
    # We have squared errors, so we take the sqrt to get error in physical units (m, rad)
    df['pos_err'] = np.sqrt(df['pos_err_sq'])
    df['orient_err'] = np.sqrt(df['orient_err_sq'])
    
    # Calculate statistics
    mse_pos = df['pos_err_sq'].mean()
    mse_orient = df['orient_err_sq'].mean()
    rmse_pos = np.sqrt(mse_pos)
    rmse_orient = np.sqrt(mse_orient)
    
    print(f"Overall Position MSE:      {mse_pos:.6f} m^2")
    print(f"Overall Orientation MSE:   {mse_orient:.6f} rad^2")
    print(f"Overall Position RMSE:     {rmse_pos:.6f} m")
    print(f"Overall Orientation RMSE:  {rmse_orient:.6f} rad")
    
    # Plotting
    # Layout: 2 rows, 1 column for plots. A separate figure or text for summary not strictly needed if title includes it.
    # But sticking to the user request for plots.
    
    fig, axs = plt.subplots(2, 1, figsize=(10, 8), sharex=True)
    
    # Relative time
    time_rel = df['time'] - df['time'].iloc[0]

    # 1. Position Error over time
    axs[0].plot(time_rel, df['pos_err'], color='dodgerblue', label='Pos Error')
    axs[0].set_title(f"Position Error vs Time (RMSE: {rmse_pos:.4f} m)")
    axs[0].set_ylabel('Error [m]')
    axs[0].grid(True, linestyle='--', alpha=0.7)
    axs[0].legend()

    # 2. Orientation Error over time
    axs[1].plot(time_rel, df['orient_err'], color='darkorange', label='Orient Error')
    axs[1].set_title(f"Orientation Error vs Time (RMSE: {rmse_orient:.4f} rad)")
    axs[1].set_xlabel('Time [s]')
    axs[1].set_ylabel('Error [rad]')
    axs[1].grid(True, linestyle='--', alpha=0.7)
    axs[1].legend()

    plt.tight_layout()
    
    output_img = "square_mover_results.png"
    plt.savefig(output_img)
    print(f"Plots saved to {output_img}")
    # plt.show() # Commented out for headless environment

if __name__ == "__main__":
    main()
